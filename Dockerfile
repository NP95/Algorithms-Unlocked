FROM node:10
# 8, 9 Versions work

# Create app directory
WORKDIR /usr/src/node-build/services

# Install app dependencies
COPY ./package*.json   ./

RUN npm install
# RUN npm install --only=production

# Bundle app source
COPY  .   .

EXPOSE 8000
# Proper Port mapping

CMD [ "echo", "Done Build"]
CMD [ "npm", "start" ]
