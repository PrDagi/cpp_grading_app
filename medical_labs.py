import scrapy
import re

class MedicalLabsSpider(scrapy.Spider):
    name = "medical_labs"
    allowed_domains = ["kenas.go.ke"]
    start_urls = ["https://kenas.go.ke/cabs/medical-laboratories/"]

    def parse(self, response):
        wrapper = ".grid-col-tablet-1>.jet-listing-grid__item"
        medical_labs = response.css(wrapper)

        for medical_lab in medical_labs:
            output = {
                "Lab Name": medical_lab.css("h1 a::text").get(),
                "Address": medical_lab.css(".elementor-120 .elementor-element.elementor-element-d46d0ea .elementor-text-editor::text").get(),
                "Phone Number": self._get_contact(medical_lab,"phone"),
                "Email":self._get_contact(medical_lab,"email")
            }

            yield output

    def _get_contact(self, medical_lab, contact_type):
            # Use a more specific selector to extract contact information
            contacts = medical_lab.css(".jet-listing-dynamic-repeater__item span::text").getall()

            phones = []
            emails = []

            for contact in contacts:
                # Extract phone numbers and email addresses
                phones.extend([phone.strip() for phone in re.findall(r'\+?\d{1,4}[\s.-]?\d{1,4}[\s.-]?\d{1,4}[\s.-]?\d{1,4}', contact)])
                emails.extend([email.strip() for email in re.findall(r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b', contact)])

            if contact_type == "phone":
                return ",".join(phones)
            else:
                return ",".join(emails)